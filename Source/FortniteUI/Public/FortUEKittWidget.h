// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortUEKittWidget.generated.h"

class AFortPlayerController;
class UCommonButtonLegacy;
class UFortGameInstance;
class UFortLocalPlayer;
class UUEKittTexture;
class UWidget;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class FORTNITEUI_API UFortUEKittWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool CheckEnabledForPlayer(const UWidget* ParentWidget);

	UFUNCTION(BlueprintCallable)
	void Close();

	UFUNCTION(BlueprintCallable)
	bool GetSetupDone();

	UFUNCTION(BlueprintCallable)
	void Open();

	UFUNCTION(BlueprintCallable)
	void Setup(UCommonButtonLegacy* InButton, bool bInAddToViewport = false);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUEKittWidget")
	TObjectPtr<UUEKittTexture> DisplayTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUEKittWidget")
	bool bDisableWorldRendering;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUEKittWidget")
	bool bAddAccountIdToUrl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUEKittWidget")
	bool bDelayedClose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUEKittWidget")
	float CloseDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUEKittWidget")
	bool bSendKeyOnOpenClose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUEKittWidget")
	FName OpenCloseKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortUEKittWidget")
	bool bEnableDynamicResolution;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MatchmakingMode;

	UPROPERTY()
	TObjectPtr<UFortLocalPlayer> LocalPlayer;

	UPROPERTY()
	TObjectPtr<UFortGameInstance> GameInstance;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY(EditAnywhere, Category="FortUEKittWidget")
	FString KittURL;

};

