// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "Building/BuildingTypes.h"
#include "Valkyrie/FortExposedAssetProviderInterface.h"
#include "BuildingTextureData.generated.h"

class UDataTable;
class UMaterialInterface;
class UTexture2D;

UENUM(BlueprintType)
enum class EBuildingTintSource : uint8
{
	Disabled = 0,
	Custom = 1,
	Table = 2,
};

USTRUCT(BlueprintType)
struct FBuildingTintRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingTintRow")
	FColor TintColor;

};

UCLASS(EditInlineNew, MinimalAPI, BlueprintType, ClassGroup=("Building"))
class UBuildingTextureData : public UDataAsset, public IFortExposedAssetProvider
{
	GENERATED_BODY()

public:
	UFUNCTION()
	TArray<FString> GetColorOptions() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingTextureData")
	TObjectPtr<UTexture2D> Diffuse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingTextureData")
	TObjectPtr<UTexture2D> Normal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingTextureData")
	TObjectPtr<UTexture2D> Specular;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> CachedDisplacement;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NaniteDisplacement")
	TSoftObjectPtr<UTexture2D> Displacement;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NaniteDisplacement")
	float Magnitude;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NaniteDisplacement")
	float Center;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Color Tinting")
	EBuildingTintSource TintColorSource;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Color Tinting", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.BuildingTintRow"))
	TObjectPtr<UDataTable> TintColorTable;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Color Tinting", meta=(EditCondition="TintColorSource==EBuildingTintSource::Table", GetOptions="GetColorOptions"))
	FString TableColorOptions;
#endif

	UPROPERTY(EditAnywhere, Category="Color Tinting", meta=(EditCondition="TintColorSource==EBuildingTintSource::Custom"))
	FColor TintColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingTextureData")
	TObjectPtr<UMaterialInterface> OverrideMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="BuildingTextureData")
	TEnumAsByte<EFortTextureDataType::Type> Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="BuildingTextureData")
	TEnumAsByte<EFortResourceType::Type> ResourceType;

	UPROPERTY(EditAnywhere, Category="BuildingTextureData", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	float ResourceCost[6];

};

