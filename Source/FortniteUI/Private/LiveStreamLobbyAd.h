// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LiveStreamLobbyAd.generated.h"

class UCommonTextBlock;
class UPanelWidget;
class UWidgetSwitcher;

UCLASS()
class ULiveStreamLobbyAd : public UUserWidget
{
	GENERATED_BODY()

public:
	ULiveStreamLobbyAd(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="LiveStreamLobbyAd", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UWidgetSwitcher> ContentSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="LiveStreamLobbyAd", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UPanelWidget> ButtonLayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="LiveStreamLobbyAd", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UPanelWidget> CountdownLayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="LiveStreamLobbyAd", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> CountdownText;

};

