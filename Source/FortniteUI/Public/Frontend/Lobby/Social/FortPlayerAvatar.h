// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortPlayerAvatar.generated.h"

class UFortSocialUser;

UCLASS()
class UFortPlayerAvatar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortPlayerAvatar(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void RepresentLocalPlayer();

	UFUNCTION(BlueprintImplementableEvent)
	void ResetPlayerAvatar();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSetSocialUser(UFortSocialUser* InUser);

};

