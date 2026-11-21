// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortExposedActorReferences.generated.h"

class UDataTable;
class UObject;

USTRUCT()
struct FFortExposedActorReferences
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 CacheVersion;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bIsCacheSafe;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSet<TSoftObjectPtr<UObject>> AllowedAssetReferences;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSet<TSoftClassPtr<UObject>> AllowedClassReferences;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSet<TSoftObjectPtr<UObject>> ExposedAssetProviderReferences;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSet<TSoftObjectPtr<UDataTable>> UserOptionDefinitionAssetValuesDataTables;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSet<TSoftObjectPtr<UDataTable>> UserOptionDefinitionClassReferenceValuesDataTables;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSet<TSoftObjectPtr<UDataTable>> UserOptionDefinitionIconValuesDataTables;
#endif

};

