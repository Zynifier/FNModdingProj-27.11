// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "ViewModels/Social/FortSocialUserViewModel.h"
#include "FortPlayerAvatarViewModel.generated.h"

class UTexture2D;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick, DisplayName="Fort PlayerAvatar Viewmodel"))
class FORTNITEUI_API UFortPlayerAvatarViewModel : public UFortSocialUserViewModel
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAvatarViewModel")
	bool bUseLargeImage;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerAvatarViewModel")
	TObjectPtr<UTexture2D> AvatarTexture;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerAvatarViewModel")
	bool bLoading;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerAvatarViewModel")
	FColor BackgroundColor;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerAvatarViewModel")
	FColor HighlightColor;

};

