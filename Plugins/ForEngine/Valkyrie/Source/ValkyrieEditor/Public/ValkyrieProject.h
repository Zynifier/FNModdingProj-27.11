// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValkyrieProjectDescriptor.h"
#include "VkValidationFlags.h"
#include "ValkyrieProject.generated.h"

class UValkyriePerProjectUserConfig;

UCLASS(BlueprintType)
class VALKYRIEEDITOR_API UValkyrieProject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Valkyrie|Editor")
	FString GetProjectFileName() const;

	UPROPERTY()
	EVkValidationFlags ValidationFlags;

private:
	UPROPERTY()
	FString ProjectFileName;

	UPROPERTY()
	FString ProjectName;

	UPROPERTY()
	FString ProjectDirectory;

	UPROPERTY()
	FValkyrieProjectDescriptor ProjectDescriptor;

	UPROPERTY()
	bool bIsOpened;

	UPROPERTY()
	TObjectPtr<UValkyriePerProjectUserConfig> UserConfig;

};

