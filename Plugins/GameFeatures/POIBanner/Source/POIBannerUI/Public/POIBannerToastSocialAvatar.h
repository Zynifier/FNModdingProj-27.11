// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "POIBannerToastSocialAvatar.generated.h"

class AFortPlayerState;
class UFortSocialAvatarIcon;
class UTexture2D;

UCLASS()
class POIBANNERUI_API UPOIBannerToastSocialAvatar : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void SetSocialAvatar(const AFortPlayerState* PlayerState);

	UFUNCTION(BlueprintCallable)
	void SetSocialAvatarTexture(TSoftObjectPtr<UTexture2D> AvatarTexture);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Icon_SocialAvatar;

};

