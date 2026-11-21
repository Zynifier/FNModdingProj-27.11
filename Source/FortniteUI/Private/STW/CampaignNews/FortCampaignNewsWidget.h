// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCampaignNewsWidget.generated.h"

class UCommonTextBlock;
class UFortCampaignNewsTile;
class UHorizontalBox;
class UScrollBox;
class UVerticalBox;
enum class EAthenaNewsStyle : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignNewsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleNewsStyle(EAthenaNewsStyle NewsStyle);

	UFUNCTION(BlueprintCallable)
	void LogMotDCloseAction();

	UFUNCTION(BlueprintCallable)
	void LogMotDLobbyNavAction();

	UFUNCTION(BlueprintImplementableEvent)
	void ResetViewConfiguration();

	UFUNCTION(BlueprintImplementableEvent)
	void SingleItemConfiguration();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="NewsTileOptions", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortCampaignNewsTile> NewsTileClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="NewsTileOptions", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortCampaignNewsTile> SpotlightNewsTileClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="NewsTileOptions", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortCampaignNewsTile> SpecialEventNewsTileClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="NewsTileOptions", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortCampaignNewsTile> SpotlightSpecialEventNewsTileClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="NewsTileOptions", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortCampaignNewsTile> SpecialEvent2NewsTileClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="NewsTileOptions", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortCampaignNewsTile> SpotlightSpecialEvent2NewsTileClass;

protected:
	UFUNCTION(BlueprintCallable)
	void PlayNewsTilesIntro();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCampaignNewsWidget", meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCampaignNewsTile>> NewsTiles;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_NewsHeader;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_NewsContainer;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_NewsContainer;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_SpotlightNewsContainer;

};

