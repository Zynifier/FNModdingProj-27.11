// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPrimaryContentInterface.generated.h"

USTRUCT()
struct FORTNITEUI_API FPrimaryContentSetup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PrimaryContentSetup")
	bool bShowBottomBar;

	UPROPERTY(EditAnywhere, Category="PrimaryContentSetup")
	bool bShowChatWidget;

	UPROPERTY(EditAnywhere, Category="PrimaryContentSetup")
	bool bShowTopBar;

};

UINTERFACE(MinimalAPI)
class UFortPrimaryContentInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IFortPrimaryContentInterface
{
	GENERATED_BODY()

};

