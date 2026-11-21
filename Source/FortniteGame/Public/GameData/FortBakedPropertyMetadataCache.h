// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortBakedPropertyMetadataCache.generated.h"

USTRUCT()
struct FBakedMetadataCacheMember
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Baked Metadata")
	TMap<FName, FString> MetadataKeyValuePairs;

};

USTRUCT()
struct FBakedMetadataCacheContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Baked Metadata")
	TMap<FName, FBakedMetadataCacheMember> MetaDataToUseInBuilds;

	UPROPERTY(EditAnywhere, Category="Baked Metadata")
	bool bAuthored;

};

USTRUCT()
struct FBakedMetadataConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Automatic Bake")
	TArray<FName> MetaDataKeysToCopy;

	UPROPERTY(EditAnywhere, Category="Automatic Bake")
	bool bIncludeMembersOfMembers;

};

UCLASS()
class UFortBakedPropertyMetadataCache : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Automation Setup")
	TMap<FString, FBakedMetadataConfig> StructsOrClassesToAutomaticallyBake;

	UPROPERTY(EditAnywhere, Category="Runtime Metadata")
	TMap<FString, FBakedMetadataCacheContainer> MetadataAtRuntime;

};

