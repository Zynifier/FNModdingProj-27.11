// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLinkedAnimGraphsData.generated.h"

class UAnimInstance;

USTRUCT()
struct FFortLinkedAnimGraphsData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSubclassOf<UAnimInstance> ZiplineAnimBlueprintClass;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSubclassOf<UAnimInstance> GoopAnimBlueprintClass;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSubclassOf<UAnimInstance> DBNOAnimBlueprintClass;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSubclassOf<UAnimInstance> DBNOCarriedAnimBlueprintClass;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSubclassOf<UAnimInstance> BuildingPoseBlueprintClass;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSubclassOf<UAnimInstance> FreeFlyingBlueprintClass;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSubclassOf<UAnimInstance> WalkAnimBlueprintClass;

};

