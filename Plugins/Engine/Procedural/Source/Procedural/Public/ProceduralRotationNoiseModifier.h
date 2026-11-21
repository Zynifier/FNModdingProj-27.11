// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralRotationModifier.h"
#include "ProceduralRotationNoiseModifier.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("Modifier"))
class UProceduralRotationNoiseModifier : public UProceduralRotationModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Rotation Noise Modifier")
	float GetRandomPitchMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Noise Modifier")
	float GetRandomPitchMin() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Noise Modifier")
	float GetRandomRollMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Noise Modifier")
	float GetRandomRollMin() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Noise Modifier")
	float GetRandomYawMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Rotation Noise Modifier")
	float GetRandomYawMin() const;

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Noise Modifier")
	void SetRandomPitchMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Noise Modifier")
	void SetRandomPitchMin(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Noise Modifier")
	void SetRandomRollMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Noise Modifier")
	void SetRandomRollMin(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Noise Modifier")
	void SetRandomYawMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Rotation Noise Modifier")
	void SetRandomYawMin(float InValue);

	/** Whether scattered points will have a random roll rotation around the forward (X) axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier", meta=(InlineEditConditionToggle))
	uint8 bRandomRoll : 1;

	/** Random roll (X axis) adjustment applied to each point, inside the specified angle range in degrees */
	UPROPERTY(EditAnywhere, Category="Modifier", meta=(ClampMax="180", ClampMin="-180", EditCondition="bRandomRoll", UIMax="180", UIMin="-180", Units="deg"))
	FFloatInterval RandomRoll;

	/** Whether scattered points will have a random pitch rotation around the right (Y) axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier", meta=(InlineEditConditionToggle))
	uint8 bRandomPitch : 1;

	/** Random pitch (Y axis) adjustment applied to each point, inside the specified angle range in degrees */
	UPROPERTY(EditAnywhere, Category="Modifier", meta=(ClampMax="180", ClampMin="-180", EditCondition="bRandomPitch", UIMax="180", UIMin="-180", Units="deg"))
	FFloatInterval RandomPitch;

	/** Whether scattered points will have a random yaw rotation around the up (Z) axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier", meta=(InlineEditConditionToggle))
	uint8 bRandomYaw : 1;

	/** Random yaw (Z axis) adjustment applied to each point, inside the specified angle range in degrees */
	UPROPERTY(EditAnywhere, Category="Modifier", meta=(ClampMax="180", ClampMin="-180", EditCondition="bRandomYaw", UIMax="180", UIMin="-180", Units="deg"))
	FFloatInterval RandomYaw;

};

