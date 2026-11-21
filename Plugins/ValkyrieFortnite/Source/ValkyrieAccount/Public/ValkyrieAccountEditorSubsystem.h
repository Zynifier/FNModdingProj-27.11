// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "UObject/SoftObjectPath.h"
#include "ValkyrieAccountEditorSubsystem.generated.h"

class UValkyrieAccountStatus;
class UValkyrieOnlineInstance;

UCLASS(Config=Engine, BlueprintType)
class VALKYRIEACCOUNT_API UValkyrieAccountEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsValkyrieLoggedIn() const;

private:
	UPROPERTY(Transient)
	TObjectPtr<UValkyrieOnlineInstance> ValkyrieOnlineInstance;

	UPROPERTY(Transient)
	TObjectPtr<UValkyrieAccountStatus> LoginStatus;

	UPROPERTY(Config)
	FSoftClassPath InitLoginStatusClassPath;

	UPROPERTY(Config)
	FSoftClassPath RuntimeLoginStatusClassPath;

};

