// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "FortItemQuantityPair.h"
#include "FortMtxOfferData.generated.h"

class UMaterialInterface;
class UObject;

UENUM(BlueprintType)
enum class EFortMtxOfferDisplaySize : uint8
{
	Small = 0,
	Medium = 1,
	Large = 2,
};

USTRUCT(BlueprintType)
struct FFortMtxDetailsAttribute
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxDetailsAttribute")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxDetailsAttribute")
	FText Value;

};

USTRUCT(BlueprintType)
struct FFortMtxDescriptionAndDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxDescriptionAndDetails", meta=(MultiLine="true"))
	FText ShortDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxDescriptionAndDetails")
	TArray<FFortMtxDetailsAttribute> AssociatedDetailsAttributes;

};

USTRUCT(BlueprintType)
struct FFortMtxGradient
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxGradient")
	FLinearColor Start;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxGradient")
	FLinearColor Stop;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortMtxOfferData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FSlateBrush CreateBrushFromAsset(UObject* LoadedAsset, const FVector2D& BrushSize);

	UFUNCTION(BlueprintPure)
	TArray<FFortMtxDescriptionAndDetails> GetDescriptionAndDetailsList() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData", meta=(MultiLine="true"))
	FText Header;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	FText ShortDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData", meta=(MultiLine="true"))
	FText ShortDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData", meta=(MultiLine="true"))
	FText SubTitleText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData", meta=(MultiLine="true"))
	FText DisclaimerText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	TArray<FFortItemQuantityPair> GrantOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> SoftTileImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	FVector2D TileImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> SoftBadgeImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	FVector2D BadgeImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> SoftDetailsImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	FVector2D DetailsImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> SoftSimpleImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	FVector2D SimpleImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	TSoftObjectPtr<UMaterialInterface> DetailsBadge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	TArray<FFortMtxDetailsAttribute> DetailsAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	FFortMtxGradient Gradient;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	FLinearColor Background;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> SoftBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMtxOfferData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	FVector2D BackgroundImageSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	FLinearColor UpsellPrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	FLinearColor UpsellSecondaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	FLinearColor UpsellTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	bool bUseBaseColors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMtxOfferData")
	EFortMtxOfferDisplaySize DisplaySize;

private:
	UPROPERTY(EditAnywhere, Category="FortMtxOfferData")
	TArray<FFortMtxDescriptionAndDetails> DescriptionAndDetailsList;

};

