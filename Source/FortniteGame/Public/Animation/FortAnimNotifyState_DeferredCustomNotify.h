// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_DeferredCustomNotify.generated.h"

UCLASS(HideCategories=("Object"), meta=(DisplayName="Deferred Custom Notify"))
class UFortAnimNotifyState_DeferredCustomNotify : public UAnimNotifyState
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_DeferredCustomNotify")
	FName NotifyName;

};

