// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "CPPTestPlayer.generated.h"


class UInputComponent;

UCLASS()
class TESTCPP_API ACPPTestPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPPTestPlayer();

	//First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float val);
	void MoveRight(float val);

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	virtual void Landed(const FHitResult& hit) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void SimpleAction();

	UFUNCTION()
		void DoubleJump();

	UPROPERTY()
		int g_doubleJumpCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float g_jumpHeight;

	UFUNCTION()
		void Sprint();

	UFUNCTION()
		void Walk();

	UPROPERTY(EditAnywhere)
		float g_walkSpeed;

	UPROPERTY(EditAnywhere)
		float g_runSpeed;
};
