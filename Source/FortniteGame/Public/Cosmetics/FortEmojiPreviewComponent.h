// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortEmojiPreviewComponent.generated.h"

class UAthenaEmojiItemDefinition;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent))
class UFortEmojiPreviewComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Emoji")
	void PushPreviewEmoji(const UAthenaEmojiItemDefinition* EmojiItem);

};

