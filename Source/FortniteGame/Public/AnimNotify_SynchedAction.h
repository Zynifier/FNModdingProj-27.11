// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_SynchedAction.generated.h"

UCLASS(MinimalAPI, HideCategories=("Object"))
class UAnimNotify_SynchedAction : public UAnimNotify
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AnimNotify_SynchedAction")
	bool bStartFallingPhysic;

};

