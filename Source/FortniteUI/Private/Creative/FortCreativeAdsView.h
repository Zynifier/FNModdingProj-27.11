// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Context/CMSContext.h"
#include "FortCreativeAdsView.generated.h"

UCLASS()
class UFortCreativeAdsView : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCreativeAdsView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativeAdsView")
	TArray<FCreativeAdData> CreativeAdList;

};

