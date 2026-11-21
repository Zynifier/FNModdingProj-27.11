// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_RhinoBackpack.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_RhinoBackpack : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_RhinoBackpack")
	FVector Piston1Movement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_RhinoBackpack")
	FVector Piston2Movement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_RhinoBackpack")
	FVector Piston3Movement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float Piston1SinOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float Piston2SinOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float Piston3SinOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float DefaultPistonSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float FastPistonSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float FastPistonThreshold;

};

