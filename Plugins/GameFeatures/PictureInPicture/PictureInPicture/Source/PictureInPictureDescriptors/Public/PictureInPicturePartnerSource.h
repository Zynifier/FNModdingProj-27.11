// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Styling/SlateBrush.h"
#include "UObject/NoExportTypes.h"
#include "FortMediaEventsSubsystem.h"
#include "PictureInPicturePartnerData.h"
#include "PictureInPicturePartnerSource.generated.h"

class UEpicCMSImage;
class UPictureInPictureSourceActionData;

UENUM(BlueprintType)
enum class PictureInPictureSourceType : uint8
{
	NONE = 0,
	URL = 1,
	BLURL = 2,
	EXTERNAL_ASSETS = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPiPPartnerSourceAction, FString, SourceActionSelected);

USTRUCT(BlueprintType)
struct PICTUREINPICTUREDESCRIPTORS_API FPiPPartnerSource
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	PictureInPictureSourceType SourceType;

	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	FDateTime StartTime;

	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	FDateTime EndTime;

	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	FFortMediaEventsStreamAssets AssetConfig;

	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	FString EventIconUrl;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UEpicCMSImage> CMSImage;

	UPROPERTY()
	TObjectPtr<UPictureInPictureSourceActionData> ActionData;

	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	TSet<FString> PlatformDenylist;

	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	TSet<FString> GameplayTagDenylist;

	UPROPERTY(BlueprintReadWrite, Category="PiPPartnerSource")
	TSet<FString> GameplayTagAllowlist;

	UPROPERTY()
	bool bManual;

};

UCLASS(BlueprintType, Blueprintable)
class PICTUREINPICTUREDESCRIPTORS_API UPictureInPictureActionData : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void CallEvent();

	UPROPERTY(BlueprintReadWrite, Category="PictureInPictureActionData")
	FString PartnerName;

	UPROPERTY(BlueprintReadWrite, Category="PictureInPictureActionData")
	FSlateBrush ActionBrush;

	UPROPERTY(BlueprintReadWrite, Category="PictureInPictureActionData")
	FText ActionText;

	UPROPERTY(BlueprintReadWrite, Category="PictureInPictureActionData")
	PictureInPictureAction ActionType;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable, Category="PictureInPictureActionData")
	FPictureInPictureActionEvent ActionEvent;

	UPROPERTY()
	FPictureInPictureActionFiredEvent ActionFiredEvent;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="PictureInPictureActionData")
	FPictureInPictureActionCallbackEvent CallbackEvent;

};

UCLASS(BlueprintType, Blueprintable)
class PICTUREINPICTUREDESCRIPTORS_API UPictureInPictureSourceActionData : public UPictureInPictureActionData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PictureInPictureSourceActionData")
	FString SourceName;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable, Category="PictureInPictureSourceActionData")
	FPiPPartnerSourceAction SourceActionEvent;

};

