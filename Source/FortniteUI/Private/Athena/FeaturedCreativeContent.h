// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Context/CMSContext.h"
#include "FeaturedCreativeContent.generated.h"

UCLASS()
class UFeaturedCreativeContent : public UUserWidget
{
	GENERATED_BODY()

public:
	UFeaturedCreativeContent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupAds(const TArray<FString>& MediaURLs, const TArray<FCreativeAdData>& AdMetadata);

};

