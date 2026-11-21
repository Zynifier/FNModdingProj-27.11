// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EmporiumProjectCatalogTypes.generated.h"

USTRUCT()
struct EMPORIUM_API FEmporiumProjectsCatalogEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectName;

	UPROPERTY()
	FString ProjectDescription;

	UPROPERTY()
	FString ProjectTeamId;

	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FString ProjectModuleId;

	UPROPERTY()
	FString ProjectLinkCode;

	UPROPERTY()
	bool bProjectProcessed;

	UPROPERTY()
	FString InputFile;

	UPROPERTY()
	FString ModelName;

	UPROPERTY()
	FString LodPreset;

	UPROPERTY()
	bool bGenLod;

	UPROPERTY()
	bool bGenCollisions;

	UPROPERTY()
	bool bPreferFoliageMaterial;

};

USTRUCT()
struct EMPORIUM_API FEmporiumProjectsCatalog
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FEmporiumProjectsCatalogEntry> Entries;

};

