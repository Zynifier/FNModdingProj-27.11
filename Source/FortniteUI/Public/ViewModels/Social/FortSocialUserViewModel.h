// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortSocialUserViewModel.generated.h"

class UFortSocialUser;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick, DisplayName="Fort SocialUser Viewmodel"))
class UFortSocialUserViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortSocialUser* GetSocialUser() const;

	UFUNCTION(BlueprintCallable)
	void SetShouldForceUpdateUser(bool bNewForceUpdateUser);

	UFUNCTION(BlueprintCallable)
	void SetSocialUser(UFortSocialUser* InSocialUser);

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<UFortSocialUser> SocialUser;

};

