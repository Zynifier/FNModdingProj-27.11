// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeTags.h"
#include "FortEmporiumUtilities.h"
#include "Items/FortItemDefinition.h"
#include "FortEmporiumItemDefinition.generated.h"

class UFortEmporiumItemDefinition;
class UTexture2D;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmporiumThumbnailDownloadedDelegate, UFortEmporiumItemDefinition*, ItemDefinition);

USTRUCT(BlueprintType)
struct FFortEmporiumItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString Id;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString Namespace;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString EntityType;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString ThumbnailURL;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	float Price;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString BaseCurrency;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString SketchfabUID;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	TArray<FName> TagList;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	EFortEmporiumItemLicense LicenseType;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	bool bRequiresEntitlement;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString VersePath;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	TArray<FString> AssetIds;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	int32 FileSize;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString Description;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	FString Seller;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	int32 MaterialCount;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	int32 PolygonCount;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	int32 VertexCount;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemData")
	int32 ChildAssetCount;

};

UCLASS()
class UFortEmporiumItemDefinition : public UFortItemDefinition, public IFortCreativeTagsBearer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FFortEmporiumItemData& GetEmporiumItemData() const;

	UPROPERTY(BlueprintAssignable)
	FEmporiumThumbnailDownloadedDelegate OnItemThumbnailDownloaded;

private:
	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> ThumbnailTexture;

};

