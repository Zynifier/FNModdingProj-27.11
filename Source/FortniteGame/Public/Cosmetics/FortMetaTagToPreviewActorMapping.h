// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortMetaTagToPreviewActorMapping.generated.h"

class AFortItemPreviewActor;

UCLASS()
class UFortMetaTagToPreviewActorMapping : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMetaTagToPreviewActorMapping", meta=(Categories="Cosmetics.MetaTags.OverridePreviewActor"))
	TMap<FGameplayTag, TSoftClassPtr<AFortItemPreviewActor>> MetaTagToPreviewActor;

};

