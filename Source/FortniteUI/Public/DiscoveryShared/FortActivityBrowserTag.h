// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortActivityBrowserTag.generated.h"

class UCommonTextBlock;
enum class EFortActivityBrowserTagType : uint8;

UENUM(BlueprintType)
enum class EFortActivityBrowserTagType : uint8
{
	Default = 0,
	EpicOriginal = 1,
	SquadSize = 2,
	MaxPlayers = 3,
	XP = 4,
	PurchaseRequired = 5,
	DownloadRequired = 6,
};

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortActivityBrowserTag : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortActivityBrowserTag(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	EFortActivityBrowserTagType GetTagType() const;

	UFUNCTION(BlueprintCallable)
	void SetTextAndType(const FText& InText, EFortActivityBrowserTagType NewTagType = EFortActivityBrowserTagType::Default);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTagUpdated();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserTag", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TagDescription;

};

