// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "Misc/DateTime.h"
#include "CommonButtonLegacy.h"
#include "EpicCMSTile.generated.h"

class UCommonLazyImage;
class UCommonTextBlock;
class UCommonTextStyle;
class UTexture2D;

UENUM(BlueprintType)
enum class EDateType : uint8
{
	None = 0,
	Coming = 1,
	Ending = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCMSTileConfirmed, bool, bSuccess);

USTRUCT(BlueprintType)
struct FTileDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FString TypeString;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FString Subtitle;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FString Eyebrow;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FString Link;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FString GroupID;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FDateTime Countdown;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	EDateType CountdownType;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FString MediaUrl;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	bool IsVisible;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class EPICCMSUIFRAMEWORK_API UEpicCMSTileBase : public UCommonButtonLegacy, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="CMS Tile")
	void Launch();

	UPROPERTY(EditDefaultsOnly, Category="Style")
	TSubclassOf<UCommonTextStyle> DefaultTitleTextStyle;

	UPROPERTY(EditDefaultsOnly, Category="Style")
	TSubclassOf<UCommonTextStyle> FeaturedTitleTextStyle;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FText Title;

	UPROPERTY(BlueprintReadOnly, Category="CMS Tile")
	FString Link;

	UPROPERTY()
	bool bDownloadingExternalMedia;

	UPROPERTY()
	bool bRefreshingMcpCatalog;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> ExternalMedia;

	UPROPERTY(BlueprintReadWrite, Export, Category="CMS Tile", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

	UPROPERTY(BlueprintReadWrite, Export, Category="CMS Tile", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> TitleTextBlock;

	UPROPERTY(BlueprintReadWrite, Export, Category="CMS Tile", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> SubtitleTextBlock;

	UPROPERTY(BlueprintReadWrite, Export, Category="CMS Tile", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> EyebrowTextBlock;

};

