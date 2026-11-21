// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/ViewModels/FortTabViewModel.h"
#include "Online/FortMcpContext.h"
#include "FortMTXTabViewModel.generated.h"

UCLASS()
class UFortMTXTabViewModel : public UFortTabViewModel
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleLocalAccountInfoChanged(FFortPrivateAccountInfo NewInfo);

};

