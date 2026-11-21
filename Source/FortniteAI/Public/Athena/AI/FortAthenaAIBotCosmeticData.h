// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortAthenaAIBotCosmeticData.generated.h"

class UFortAthenaAIBotCosmeticLibraryData;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAIBotCosmeticData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI")
	TSoftObjectPtr<UFortAthenaAIBotCosmeticLibraryData> FindLibraryDataFromName(const FString& PartialName);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization", meta=(AllowPrivateAccess="true", AssetBundles="Server"))
	TArray<TSoftObjectPtr<UFortAthenaAIBotCosmeticLibraryData>> CosmeticLibraries;

};

