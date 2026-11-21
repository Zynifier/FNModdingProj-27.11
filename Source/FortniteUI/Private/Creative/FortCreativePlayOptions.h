// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCreativePlayOptions.generated.h"

class UCommonButtonLegacy;
class UFortCreativeServersView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativePlayOptions : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void HandleCancelClicked();

	UFUNCTION(BlueprintCallable)
	void ImportPlatformFriends();

	UFUNCTION(BlueprintCallable)
	bool ShouldShowImportPlatformFriendsOption();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePlayOptions", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeServersView> View_CreativeOptionsServers;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePlayOptions", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Play;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePlayOptions", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

};

