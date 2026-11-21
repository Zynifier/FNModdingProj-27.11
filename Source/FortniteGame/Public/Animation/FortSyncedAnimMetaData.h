// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "FortSyncedAnimMetaData.generated.h"

class UAnimMontage;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object"))
class UFortSyncedAnimMetaData : public UAnimMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimMontage> SyncedMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimMontage> SyncedMontageFemaleOverride;

};

