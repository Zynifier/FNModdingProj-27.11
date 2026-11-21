// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "FortCharacterPartSyncedSequenceMetaData.generated.h"

class UAnimSequence;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object"))
class UFortCharacterPartSyncedSequenceMetaData : public UAnimMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimSequence> SyncedSequence;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	int32 Priority;

};

