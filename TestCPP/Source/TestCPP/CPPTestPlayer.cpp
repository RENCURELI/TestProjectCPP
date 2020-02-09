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
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACPPTestPlayer::Jump);

	//Movement
	PlayerInputComponent->BindAxis("Forward", this, &ACPPTestPlayer::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &ACPPTestPlayer::MoveRight);

	//Mouse controls
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
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

void ACPPTestPlayer::Jump()
{
	//Waiting for more code
}