// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SocialSoundSchema.h"
#include "SocialSoundSchemaDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialSoundSchemaDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FSocialSoundSchema SoundSchema;

};

