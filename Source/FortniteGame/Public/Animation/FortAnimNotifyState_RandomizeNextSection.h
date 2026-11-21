// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_RandomizeNextSection.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_RandomizeNextSection : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RandomizeNextSection")
	int32 MinLoopsBeforeChange;

	UPROPERTY(EditAnywhere, Category="RandomizeNextSection")
	int32 MaxLoopsBeforeChange;

	UPROPERTY(EditAnywhere, Category="RandomizeNextSection")
	TArray<FName> SectionsToJumpTo;

};

