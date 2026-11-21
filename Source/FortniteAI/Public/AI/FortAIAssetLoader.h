// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAIAssetLoader.generated.h"

class UObject;

USTRUCT()
struct FPendingRequestManager
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortAIAssetLoader : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FPendingRequestManager> PendingRequests;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> AssetsLoaded;

};

