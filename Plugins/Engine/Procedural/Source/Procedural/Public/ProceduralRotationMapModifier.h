// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralRotationFormat.h"
#include "ProceduralRotationModifier.h"
#include "ProceduralRotationMapModifier.generated.h"

class UProceduralVectorDataMap;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("Modifier"))
class UProceduralRotationMapModifier : public UProceduralRotationModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Rotation Map Modifier")
	float GetPitchMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Map Modifier")
	float GetPitchMin() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Map Modifier")
	float GetRollMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Map Modifier")
	float GetRollMin() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Map Modifier")
	float GetYawMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Map Modifier")
	float GetYawMin() const;

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Map Modifier")
	void SetPitchMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Map Modifier")
	void SetPitchMin(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Map Modifier")
	void SetRollMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Map Modifier")
	void SetRollMin(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Map Modifier")
	void SetYawMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Map Modifier")
	void SetYawMin(float InValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Modifier")
	TObjectPtr<UProceduralVectorDataMap> Map;

	/** Controls how texture channels are interpreted. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier")
	EProceduralRotationFormat RotationFormat;

	/** Roll (X axis) range in degrees (used with Ranged Rotator rotation format). */
	UPROPERTY(EditAnywhere, Category="Modifier", meta=(ClampMax="360", ClampMin="-360", EditCondition="RotationFormat == EProceduralRotationFormat::RangedRotator", UIMax="360", UIMin="-360", Units="deg"))
	FFloatInterval Roll;

	/** Pitch (Y axis) range in degrees (used with Ranged Rotator rotation format). */
	UPROPERTY(EditAnywhere, Category="Modifier", meta=(ClampMax="360", ClampMin="-360", EditCondition="RotationFormat == EProceduralRotationFormat::RangedRotator", UIMax="360", UIMin="-360", Units="deg"))
	FFloatInterval Pitch;

	/** Yaw (Z axis) range in degrees (used with Ranged Rotator rotation format). */
	UPROPERTY(EditAnywhere, Category="Modifier", meta=(ClampMax="360", ClampMin="-360", EditCondition="RotationFormat == EProceduralRotationFormat::RangedRotator", UIMax="360", UIMin="-360", Units="deg"))
	FFloatInterval Yaw;

};

