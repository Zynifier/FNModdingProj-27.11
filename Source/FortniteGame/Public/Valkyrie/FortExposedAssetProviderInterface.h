// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortExposedAssetProviderInterface.generated.h"

USTRUCT(BlueprintType)
struct FFortExposedAssetProviderVersion
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint32 VersionHash;

};

USTRUCT(BlueprintType)
struct FFortExposedAssetReferenceCollector
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortExposedClassReferenceCollector
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI)
class UFortExposedAssetProvider : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortExposedAssetProvider
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="ExposedAssetProvider", meta=(DisplayName="Build Exposed Asset Provider Version (Implementation)"))
	void BuildExposedAssetProviderVersion(UPARAM(ref) FFortExposedAssetProviderVersion& Version) const;

	UFUNCTION(BlueprintNativeEvent, Category="ExposedAssetProvider", meta=(DisplayName="Collect Asset References to Allow (Implementation)"))
	void CollectAssetReferencesToAllow(UPARAM(ref) FFortExposedAssetReferenceCollector& Collector) const;

	UFUNCTION(BlueprintNativeEvent, Category="ExposedAssetProvider", meta=(DisplayName="Collect Class References to Allow (Implementation)"))
	void CollectClassReferencesToAllow(UPARAM(ref) FFortExposedClassReferenceCollector& Collector) const;

	UFUNCTION(BlueprintNativeEvent, Category="ExposedAssetProvider", meta=(DisplayName="Collect Exposed Asset Provider References (Implementation)"))
	void CollectExposedAssetProviderReferences(UPARAM(ref) FFortExposedAssetReferenceCollector& Collector) const;

};

