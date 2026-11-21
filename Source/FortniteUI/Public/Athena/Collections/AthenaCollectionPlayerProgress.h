// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaCollectionPlayerProgress.generated.h"

class UCommonTextBlock;
class UFortSocialAvatarIcon;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionPlayerProgress : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetNumCollected() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayer() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Player Progress Initialized"))
	void BP_OnPlayerProgressInitialized(bool bIsLocalPlayer, int32 NumCollected, int32 NumToCollect);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Show Player Info Set"))
	void BP_OnShowPlayerInfoSet(bool bShowPlayerInfo);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionPlayerProgress", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionPlayerProgress", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Progress;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionPlayerProgress", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> AvatarIcon;

};

