// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance_SyncedPart.h"
#include "CustomCharacterPartAnimInstance_ProfPupBody.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_ProfPupBody : public UCustomCharacterPartAnimInstance_SyncedPart
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	FRotator WheelRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float WheelAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float SkydiveReduceAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float DynamicsAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float VehicleOrSkydivingOffAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float CatBodyAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float MechBodyAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float AdditiveIdleAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float ModifyTailAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float TraversalEmoteTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float CurrentLODValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float BaseWheelSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	float TreadmillBaseSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	bool bTurnOnBreaklight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	bool bLongBackbling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	bool bShortBackbling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ProfPupBody")
	bool bIsBlendingTraversalEmote;

};

