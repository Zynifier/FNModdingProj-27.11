// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Valkyrie/Animation/BaseUEFNAnimInstance.h"
#include "UEFNCustomAgentAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UUEFNCustomAgentAnimInstance : public UBaseUEFNAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Pawn")
	FVector FocusLocation;

};

