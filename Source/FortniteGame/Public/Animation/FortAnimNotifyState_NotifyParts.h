// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_NotifyParts.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_NotifyParts : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="NotifyParts")
	FName Context;

};

