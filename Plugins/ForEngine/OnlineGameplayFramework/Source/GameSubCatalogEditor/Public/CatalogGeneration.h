// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CatalogGeneration.generated.h"

USTRUCT()
struct FLocalizedCatalogSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="LocalizedCatalogSettings")
	FString Name;

	UPROPERTY(EditAnywhere, Config, Category="LocalizedCatalogSettings")
	FString LocalizedCatalogFileName;

	UPROPERTY(EditAnywhere, Config, Category="LocalizedCatalogSettings")
	FString ExportCatalogFileName;

	UPROPERTY(EditAnywhere, Config, Category="LocalizedCatalogSettings")
	FString ExportLocalizationCatalogFileName;

	UPROPERTY(EditAnywhere, Config, Category="LocalizedCatalogSettings")
	FString TemplateName;

	UPROPERTY(EditAnywhere, Config, Category="LocalizedCatalogSettings")
	TArray<FString> SuppressCultures;

};

UCLASS(Abstract)
class GAMESUBCATALOGEDITOR_API UStoreAssetGatherer : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract, Config=Editor, DefaultConfig)
class GAMESUBCATALOGEDITOR_API UStoreBranchSpecificCatalogExport : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FLocalizedCatalogSettings> LocalizedCatalogSettings;

};

UCLASS()
class GAMESUBCATALOGEDITOR_API UStoreCanonicalExport : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class GAMESUBCATALOGEDITOR_API UStoreOfferGatherer : public UObject
{
	GENERATED_BODY()

};

