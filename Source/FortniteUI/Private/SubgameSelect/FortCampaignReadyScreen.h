// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonActivatableWidget.h"
#include "FortGameActivity.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortCampaignReadyScreen.generated.h"

class UCommonActivatableWidget;
class UDynamicEntryBox;
class UFortCampaignPurchaseScreen;
class UFortLoadingOnDemandContentModal;
enum class EActivityCheckSolution : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortActivtyCheckLine : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortActivtyCheckLine(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void Configure(const FGameActivityCheck& Check);

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignReadyScreen : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void CloseDialog();

	UFUNCTION(BlueprintImplementableEvent)
	void ConfigureButtons(const EActivityCheckSolution Solution);

	UFUNCTION(BlueprintCallable)
	void InstallSaveTheWorldContent();

	UFUNCTION(BlueprintCallable)
	void LeavePartyAndPlayTutorial();

	UFUNCTION(BlueprintCallable)
	void ShowPurchaseScreen();

	UFUNCTION(BlueprintCallable)
	void ShowSettingsScreen();

	UFUNCTION()
	void ShowSTWManualInstallConfirmation();

	UPROPERTY(EditDefaultsOnly, Category="FortCampaignReadyScreen")
	TSubclassOf<UFortCampaignPurchaseScreen> CampaignPurchaseScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCampaignReadyScreen")
	TSubclassOf<UFortLoadingOnDemandContentModal> LoadingContentModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCampaignReadyScreen")
	TSubclassOf<UCommonActivatableWidget> SettingsScreenClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> LinesEntryBox;

};

