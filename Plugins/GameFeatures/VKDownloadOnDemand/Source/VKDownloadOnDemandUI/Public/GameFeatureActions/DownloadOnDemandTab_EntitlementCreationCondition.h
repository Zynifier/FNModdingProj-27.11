// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/GameFeatureActions/CreativeContentBrowser/CreativeContentBrowserTab_CreationCondition.h"
#include "DownloadOnDemandTab_EntitlementCreationCondition.generated.h"

UCLASS()
class UDownloadOnDemandTab_EntitlementCreationCondition : public UCreativeContentBrowserTab_CreationCondition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="DownloadOnDemandTab_EntitlementCreationCondition")
	FString EntitlementName;

};

