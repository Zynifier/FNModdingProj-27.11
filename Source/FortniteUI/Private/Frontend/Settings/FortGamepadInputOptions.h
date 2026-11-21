// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Settings/FortInputOptions.h"
#include "FortGamepadInputOptions.generated.h"

enum class ECommonGamepadType : uint8;

UCLASS(meta=(DisableNativeTick))
class UFortGamepadInputOptions : public UFortInputOptions
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	bool AreAllImportantActionsBound(TArray<FText>& OutUnboundScreenLabels, const bool bRichText = false);

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	FString GetControllerPlatform() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="FortGameOptions")
	void HandleGamePadToggleMode();

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool HasCustomGamepadBindingChanges() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool IsCustomGamepadConfig(const FString& ConfigName) const;

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void ResetCustomGamepadToDefault();

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetControllerPlatform(const FString& InControllerPlatform);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetControllerPlatformEnum(const ECommonGamepadType InControllerPlatform);

private:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortGameOptions")
	void BroadcastModalClosed() const;

};

