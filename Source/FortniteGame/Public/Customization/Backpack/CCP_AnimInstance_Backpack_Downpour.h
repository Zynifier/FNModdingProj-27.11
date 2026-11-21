// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Backpack_Downpour.generated.h"

USTRUCT(BlueprintType)
struct FCCP_Backpack_Downpour_AmbientMovementSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Downpour|Settings")
	float TimeOffset;

	UPROPERTY(EditAnywhere, Category="Downpour|Settings")
	FVector Period;

	UPROPERTY(EditAnywhere, Category="Downpour|Settings")
	float PeriodMultiplier;

	UPROPERTY(EditAnywhere, Category="Downpour|Settings")
	FVector Magnitude;

	UPROPERTY(EditAnywhere, Category="Downpour|Settings")
	float MagnitudeMultiplier;

	UPROPERTY(EditAnywhere, Category="Downpour|Settings")
	float RotateMultiplier;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Backpack_Downpour : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Downpour|Native Functions")
	void AmbientMovement(FVector& VectorOut, FRotator& RotateOut, const FCCP_Backpack_Downpour_AmbientMovementSettings& Settings) const;

	UFUNCTION(BlueprintPure, Category="Downpour|Native Functions")
	void AmbientMovementEx(FVector& VectorOut, FRotator& RotateOut, float TimeOffset, FVector Period, FVector Magnitude, float PeriodMultiplier = 1.000000f, float MagnitudeMultiplier = 1.000000f, float RotateMultiplier = 1.000000f) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Downpour|Settings")
	FCCP_Backpack_Downpour_AmbientMovementSettings Spike1_Translation_Settings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Downpour|Settings")
	FCCP_Backpack_Downpour_AmbientMovementSettings Spike2_Translation_Settings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Downpour|Settings")
	FCCP_Backpack_Downpour_AmbientMovementSettings Spike3_Translation_Settings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Downpour|Settings")
	FCCP_Backpack_Downpour_AmbientMovementSettings Spike1_Rotation_Settings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Downpour|Settings")
	FCCP_Backpack_Downpour_AmbientMovementSettings Spike2_Rotation_Settings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Downpour|Settings")
	FCCP_Backpack_Downpour_AmbientMovementSettings Spike3_Rotation_Settings;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Downpour|Native Properties")
	FVector AmbientTrans_Spike1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Downpour|Native Properties")
	FVector AmbientTrans_Spike2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Downpour|Native Properties")
	FVector AmbientTrans_Spike3;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Downpour|Native Properties")
	FRotator AmbientRot_Spike1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Downpour|Native Properties")
	FRotator AmbientRot_Spike2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Downpour|Native Properties")
	FRotator AmbientRot_Spike3;

};

