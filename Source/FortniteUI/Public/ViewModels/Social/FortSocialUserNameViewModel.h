// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ViewModels/Social/FortSocialUserViewModel.h"
#include "FortSocialUserNameViewModel.generated.h"

UENUM(BlueprintType)
enum class EFortSocialPlatformTagDisplayRule : uint8
{
	Never = 0,
	OnlyIfDifferent = 1,
	Always = 2,
};

USTRUCT(BlueprintType)
struct FFortSocialUserNamePackage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserNamePackage")
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserNamePackage")
	FString Nickname;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserNamePackage")
	FString PlatformIconTag;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick, DisplayName="Fort SocialUser Name Viewmodel"))
class UFortSocialUserNameViewModel : public UFortSocialUserViewModel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserNameViewModel")
	FFortSocialUserNamePackage SocialUserNames;

	UPROPERTY(BlueprintReadWrite, Category="FortSocialUserNameViewModel")
	EFortSocialPlatformTagDisplayRule PlatformTagDisplayRule;

};

