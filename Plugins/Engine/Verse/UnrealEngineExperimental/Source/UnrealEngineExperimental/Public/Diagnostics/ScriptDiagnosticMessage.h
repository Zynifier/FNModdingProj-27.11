// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LocalizableMessage.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "ScriptDiagnosticMessage.generated.h"

UENUM()
namespace EScriptDiagnosticMessageType
{
	enum Type
	{
		Debug = 0,
		Verbose = 1,
		Normal = 2,
		Warning = 3,
		Error = 4,
	};
}

USTRUCT()
struct FScriptDiagnosticSourceLocation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString FilePath;

	UPROPERTY()
	FIntPoint RowSpan;

	UPROPERTY()
	FIntPoint ColSpan;

};

// Temporary struct used to carry diagnostics messages between the server and the editor

USTRUCT()
struct UNREALENGINEEXPERIMENTAL_API FScriptDiagnosticMessage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<EScriptDiagnosticMessageType::Type> MessageType;

	UPROPERTY()
	FDateTime Timestamp;

	UPROPERTY()
	FString Channel;

	UPROPERTY()
	FText MessageStr;

	UPROPERTY()
	FScriptDiagnosticSourceLocation SourceLocation;

};

USTRUCT()
struct UNREALENGINEEXPERIMENTAL_API FScriptScreenLogMessage : public FScriptDiagnosticMessage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FColor ScreenColor;

	UPROPERTY()
	float DisplayDuration;

};

USTRUCT()
struct UNREALENGINEEXPERIMENTAL_API FScriptScreenLogMessageWithLocalization
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime Timestamp;

	UPROPERTY()
	FLocalizableMessage Message;

	UPROPERTY()
	FString Prefix;

	UPROPERTY()
	FColor ScreenColor;

	UPROPERTY()
	float DisplayDuration;

};

