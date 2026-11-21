// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Pawns/FortPlayerPawn.h"
#include "FortAnimNotifyState_HideBodyPartGrouping.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_HideBodyPartGrouping : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HideBodyPartGrouping")
	EBodyPartVisibilityGrouping BodyPartVisibilityGrouping;

};

