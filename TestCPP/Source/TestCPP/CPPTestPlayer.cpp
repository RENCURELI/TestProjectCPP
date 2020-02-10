// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPTestPlayer.h"

// Sets default values
ACPPTestPlayer::ACPPTestPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set capsule size
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	//Create camera component
	CameraComponent = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("MainCamera")); //Create and name component
	CameraComponent->SetupAttachment(GetCapsuleComponent()); //Attach to capsule component
	CameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); //Set camera position
	CameraComponent->bUsePawnControlRotation = true;

	g_jumpHeight = 600.f;
	g_walkSpeed = 600.f;
	g_runSpeed = 1200.f;
}

// Called when the game starts or when spawned
void ACPPTestPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPTestPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPTestPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent); //Check if properly setup, IF NOT stops function preventing errors

	//Actions
	PlayerInputComponent->BindAction("SimpleAction", IE_Pressed, this, &ACPPTestPlayer::SimpleAction);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACPPTestPlayer::DoubleJump);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACPPTestPlayer::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACPPTestPlayer::Walk);

	//Movement
	PlayerInputComponent->BindAxis("Forward", this, &ACPPTestPlayer::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &ACPPTestPlayer::MoveRight);

	//Mouse controls
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

void ACPPTestPlayer::Landed(const FHitResult & hit)
{
	g_doubleJumpCount = 0;
}

void ACPPTestPlayer::MoveForward(float val)
{
	if (val != 0)
	{
		AddMovementInput(GetActorForwardVector(), val);
	}
}

void ACPPTestPlayer::MoveRight(float val)
{
	if (val != 0)
	{
		AddMovementInput(GetActorRightVector(), val);
	}
}

void ACPPTestPlayer::SimpleAction()
{
	UE_LOG(LogTemp, Warning, TEXT("E was pressed"));
}

void ACPPTestPlayer::DoubleJump()
{
	if (g_doubleJumpCount <= 1)
	{
		ACPPTestPlayer::LaunchCharacter(FVector(0 , 0 ,g_jumpHeight), false, true);
		g_doubleJumpCount++;
	}
}

void ACPPTestPlayer::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed = g_runSpeed;
}

void ACPPTestPlayer::Walk()
{
	GetCharacterMovement()->MaxWalkSpeed = g_walkSpeed;
}
