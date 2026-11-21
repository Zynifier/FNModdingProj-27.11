// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ViewModels/Social/FortSocialUserViewModel.h"
#include "FortSocialUserPartyViewModel.generated.h"

UCLASS()
class UFortSocialUserPartyViewModel : public UFortSocialUserViewModel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserPartyViewModel")
	bool bIsPartyLeader;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserPartyViewModel")
	bool bCanJoinParty;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserPartyViewModel")
	FText PartyReadiness;

};

