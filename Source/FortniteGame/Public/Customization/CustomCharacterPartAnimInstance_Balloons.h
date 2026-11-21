// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Balloons.generated.h"

class ABuildingGameplayActorBalloon;
class ACharacter;
class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Balloons : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	TObjectPtr<ACharacter> Character;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	TObjectPtr<ABuildingGameplayActorBalloon> BGABalloon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	float PawnSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	bool bIsMovingBackward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	float TrailVehicleAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	float BalloonLocationAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	FRotator BalloonSideRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	float IsFloatingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	float SpringAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	float PawnZVelCheck;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	float AimAlpha;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Balloons")
	TArray<float> ForwardLocationAlphas;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Balloons")
	TArray<float> BackwardLocationAlphas;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Balloons")
	TArray<FRotator> ForwardRotators;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Balloons")
	TArray<FRotator> BackwardRotators;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Balloons")
	float SpringMultiplier;

};

