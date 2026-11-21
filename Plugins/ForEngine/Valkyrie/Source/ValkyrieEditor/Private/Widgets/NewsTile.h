// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EpicCMSLayout.h"
#include "EpicCMSSimpleMessage.h"
#include "EpicCMSTile.h"
#include "NewsTile.generated.h"

class UCMSWelcomeMessage;
class UCMSWelcomeTileLayout;
class UEpicCMSTileBase;
class UMaterialInterface;

UCLASS()
class UCMSNewsLayoutWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UCMSNewsLayoutWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="CMS")
	static bool GetOnlyShowUnseenNewsOnStartup();

	UFUNCTION(BlueprintCallable, Category="CMS")
	static void SetOnlyShowUnseenNewsOnStartup(bool bOnlyShowUnseenNewsOnStartup);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void DataFound();

	UFUNCTION(BlueprintImplementableEvent)
	void NoData();

	UPROPERTY(BlueprintReadWrite, Export, Category="CMS", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCMSWelcomeMessage> NewsMessagePanel;

	UPROPERTY(BlueprintReadWrite, Export, Category="CMS", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCMSWelcomeTileLayout> NewsTileLayout;

};

UCLASS()
class UCMSWelcomeMessage : public UEpicCMSSimpleMessage
{
	GENERATED_BODY()

};

UCLASS()
class UCMSWelcomeTile : public UEpicCMSTileBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CMS Layout")
	TSoftObjectPtr<UMaterialInterface> TileMaterial;

};

UCLASS()
class UCMSWelcomeTileLayout : public UEpicCMSLayoutBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CMS Layout")
	TSoftClassPtr<UEpicCMSTileBase> TileType;

};

