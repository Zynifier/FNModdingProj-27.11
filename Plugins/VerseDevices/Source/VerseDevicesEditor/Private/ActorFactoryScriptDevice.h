// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorFactories/ActorFactory.h"
#include "ActorFactoryScriptDevice.generated.h"

UCLASS(HideCategories=("Object"))
class UActorFactoryScriptDevice : public UActorFactory
{
	GENERATED_BODY()

public:
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override
	{
		// The base implementation dereferences the default actor for valid assets.
		return GetDefaultActor(AssetData) != nullptr && Super::CanCreateActorFrom(AssetData, OutErrorMsg);
	}

};

