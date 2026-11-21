// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "DadPersistAssetCommandlet.generated.h"

UCLASS(Config=Editor)
class UDadPersistAssetCommandlet : public UCommandlet
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString BaseServiceUrl;

	UPROPERTY(Config)
	FString PersistAssetPath;

	UPROPERTY(Config)
	float RequestTimeout;

};

